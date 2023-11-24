#ifndef DEF_PHONEBOOK
#define DEF_PHONEBOOK

#include <iostream>
#include <string> 
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include "contact.hpp"

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();
        std::string get_question(const std::string &question);
        void stock_first_name(std::string nom);
        void stock_last_name(std::string nom);
        void stock_nick_name(std::string nom);
        void stock_phone_name(std::string nom);
        void stock_darkest(std::string nom);
        void afficher_contacts();
        void contacts_index(int index);

        void search(std::string &nom, PhoneBook &contact);
        void add(PhoneBook &contact);

        
    private:
        int nextIndex;
        Contact contact[8];
};
#endif