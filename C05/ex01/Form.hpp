#ifndef FORM_HPP
#define FORM_HPP

class Form {
public:
    Form(const std::string& name, int gradeSign, int gradeExecute, bool sign);
    ~Form();
    Form& operator= (const Form &src);
    
    const std::string& getName() const;
    int getGradeSign() const;
    int getGradeExecute() const;
    bool isSigned() const;

    void GradeIncrement();
    void GradeDecrement();
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