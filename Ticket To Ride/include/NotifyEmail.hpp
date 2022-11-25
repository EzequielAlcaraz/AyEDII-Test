#ifndef NOTIFYEMAIL_HPP
#define NOTIFYEMAIL_HPP

#include "INotify.hpp"
#include <iostream>

class NotifyEmail : public INotify
{
    private:

    public:
        NotifyEmail();
        virtual ~NotifyEmail();

        void notify();
};


#endif // !NOTIFYEMAIL_HPP