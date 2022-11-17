#include "tm.hpp"
#include <iostream>
#include <stdexcept>

#include <chrono>
#include <thread>
#include <random>

namespace TaskManager {
    //Tools-------------------------//
    std::mt19937 random_engine(std::random_device {}());

    void clear(std::size_t n = 100) {
        std::cout << "\x1B[2J\x1B[1;1H";
    }
    //------------------------------//
    
    
    //Interfaces

    //Jobs
    void displayJob(const Job& job) {
        std::cout << job.label << job.duration;
    }

    void displayJobAchievement(const Job& job) {
        std::cout << job.label << 100.0 * (job.duration - job.remaining_time) / (double)job.duration;
    }


    //Worker
    void displayWorker(const Worker& worker) {
        std::cout << worker.label;
        if(worker.jobs.empty()) {
            std::cout << " idle" << std::endl;
            return;
        }

        std::queue<Job> jobs_copy = worker.jobs;
        while(!jobs_copy.empty()) {
            displayJobAchievement(jobs_copy.front());
            jobs_copy.pop();
        }
        std::cout << std::endl;
    }

    //Display service informations
    void displayService(const Service& service) {
        clear(50);
        std::cout << "Services::" << service.label << std::endl;
        std::cout << "main queue: ";

        if(service.main_queue.empty()) {
            std::cout << "empty" << std::endl;
        } else {
            std::queue<Job> jobs_copy = service.main_queue;
            while (!jobs_copy.empty()) {
                displayJob(jobs_copy.front());
                jobs_copy.pop();
            }
        } std::cout << std::endl;

        std::cout << "frame: " << service.current_frame << std::endl;
        for(const Worker& worker : service.workers) {
            displayWorker(worker);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(125));
        std::cout << std::endl;
    }

    //True if all workers are idle
    bool idle(const Service& service) {
        bool is_empty = true;
        for(std::vector<Worker>::const_iterator it = service.workers.begin();
            it != service.workers.end() && is_empty; ++it) {
                is_empty &= (*it).jobs.empty();
            }
        return is_empty;
    }



    //Services

    Job createJob(const std::string& label, size_t duration) {
        Job job;
        job.label = label;
        job.duration = duration;
        job.remaining_time = 0;
        return job;
    }

    Worker createWorker(const std::string& label) {
        Worker worker;
        worker.label = label;
        worker.jobs = {}; 
        return worker;
    }

    Service createService(const std::string& label) {
        Service service;
        service.label = label;
        service.workers = {};
        service.main_queue = {};
        service.current_frame = 0;
        return service;
    }

    //adds job to a service
    void addJob(Service& service, const Job& job) {
        service.main_queue.push(job);
    }

    //creates a job with label and adds it to service
    void addJob(Service& service, const std::string& label, size_t job_duration) {
        Job job = createJob(label, job_duration);
        addJob(service, job);
    }

    //adds worker to service
    void addWorker(Service& service, const Worker& worker) {
        service.workers.push_back(worker);
    }

    //create a worker with label and adds it to service
    void addWorker(Service& service, const std::string& label) {
        Worker worker = createWorker(label);
        addWorker(service, worker);
    }

    //Dispactch next job to a worker
    void dispatchNextJob(Service& service, std::size_t worker_id) {
        if(worker_id > service.workers.size()-1) throw std::range_error("Ce worker n'existe pas");
        if(service.main_queue.empty()) throw std::range_error("File vide");
        
        service.workers[worker_id].jobs.push(service.main_queue.front());
        service.main_queue.pop();
    }


    //Dispatch jobs to worker using random distribution
    void dispatchAllJobs(Service& service) {
        std::uniform_int_distribution<std::size_t> dist_workers(0, service.workers.size()-1);

        while(!service.main_queue.empty()) {
            const std::size_t worker_id = dist_workers(random_engine);
            dispatchNextJob(service, worker_id);
        }
    }

    //runs the code, duh
    void run(Service &service){
        dispatchAllJobs(service);
        while(!idle(service)){
            for(Worker &worker : service.workers){
                if(!worker.jobs.empty()){
                    if(worker.jobs.front().remaining_time <= 1){
                        worker.jobs.pop();
                    } else {
                        worker.jobs.front().remaining_time--;
                    }
                }
            }
            service.current_frame++;
            displayService(service);
        }
    }

} //Namepsace TaskManager