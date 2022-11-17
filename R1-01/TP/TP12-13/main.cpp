#include <iostream>
#include <sstream>
#include <random>
#include "tm.hpp"

int main() {

    std::string str = "Passage en caisse";  
    TaskManager::Service service = TaskManager::createService(str);

    //Setup
    const size_t nb_workers = 5;
    const size_t nb_jobs = 60;

    //Generate Workers
    for(size_t n=0; n<nb_workers;++n){
        std::stringstream ss;
        ss << "Caisse" << n+1;
        TaskManager::addWorker(service, ss.str());
    }

    //Generate Jobs
    std::uniform_int_distribution<size_t> dist_duration(1,5);
    for(size_t n=0; n<nb_jobs; ++n){
        std::stringstream ss;
        ss << "Client " << n+1 << " ";
        const size_t job_duration = dist_duration(TaskManager::random_engine);
        TaskManager::addJob(service, ss.str(), job_duration);
    }

    //Run Simulation
    TaskManager::displayService(service);
    TaskManager::run(service);
    
    return 0;
}