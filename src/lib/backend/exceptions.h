// This file defines exceptions (and errors) that the program may meet.

#pragma once
#include <exception>
#include <string>

// The universal exception of this project.
class CollegeHRMException : public std::exception{
private:
    // Store the message.
    std::string msg;

public:
    CollegeHRMException(const char* msg){
        this->msg = std::string(msg);
    }

    const char* what() const throw(){
        return msg.c_str();
    }
};

// The ids of the employees should not be repeated.
class RepeatedIdException : public CollegeHRMException{
public:
    RepeatedIdException(unsigned int id):
        CollegeHRMException(std::to_string(id).c_str()){}
};

// For a GUI frontend, there is no possibility for the user to delete/revise a
// non-valid employee, so it's an error for a GUI program. But based on its
// design, it may be an exception for a CLI program.
class EmployeeNotFoundError : public CollegeHRMException{
public:
    EmployeeNotFoundError(unsigned int id):
        CollegeHRMException(std::to_string(id).c_str()){}
};