#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp" 

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string>  
class Bureaucrat ;

class Form {
public:
    Form();
    ~Form();
    Form& operator= (const Form &src);
    Form(const Form& src);
    Form(const std::string& name, int gradeSign, int gradeExecute);
    
    const std::string& getName() const;
    int getGradeSign() const;
    int getGradeExecute() const;
    bool isSigned() const;
    bool get_Grade_bool_sign() const;


    void signForm();
    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too high";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too low";
        }
    };
    
private:
    const std::string name;
    bool sign;
    const int gradeSign;
    const int gradeExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& Form);




#endif