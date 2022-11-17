#ifndef __TM_HPP__
#define __TM_HPP__

#include <string>
#include <queue>
#include <vector>
#include <random>

namespace TaskManager {

    //Tools
    extern std::mt19937 random_engine;

    //Structures
    struct Job {
        std::string label;
        std::size_t duration;
        std::size_t remaining_time;
    };

    struct Worker {
        std::string label;
        std::queue<Job> jobs;
    };

    struct Service {
        std::string label;
        std::vector<Worker> workers;
        std::queue<Job> main_queue;
        std::size_t current_frame;
    };


    //Interfaces

    //Jobs
    void diplayJob(const Job& job);
    void displayJobAchievement(const Job& job);

    //Worker
    void displayWorker(const Worker& worker);


    //Services
    Service createService(const std::string& label);
    //Jobs
    void addJob(Service& service, const Job& job);
    void addJob(Service& service, const std::string& label, size_t job_duration);
    //Workers
    void addWorker(Service& service, const Worker& worker);
    void addWorker(Service& service, const std::string& label);
    //Service
    void displayService(const Service& service);

    bool idle(const Service& service);
    void run(Service& service);
    
} //Namspace TaskManager

#endif