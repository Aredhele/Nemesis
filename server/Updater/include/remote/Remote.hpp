/**
 * \brief Remote to send files to client
 * \file Remote.hpp
 * \author Aredhele
 * \version 0.1
 * \date 20/11/2015
 * \class Remote
 */

#ifndef DEF_REMOTE_HPP
#define DEF_REMOTE_HPP

#define _MAX_HOST_LENGHT_ 100
#define _DEFAULT_HOST_PORT_ 6000

// Header
#include <sstream>
#include <winsock2.h>

#include "parser/Configuration.hpp"

class Remote;

struct thread_param {
    Remote * strt_remote;
    SOCKET strt_socket;
};

namespace utility {
    unsigned short toShortInt(std::string value);
}

class Remote
{
    private:
        Configuration * m_ptr_configuration;
        ConsoleDisplayer * m_ptr_displayer;
        DWORD m_clientThread(SOCKET);
        SOCKADDR_IN m_serverAddr;
        SOCKET m_listeningSocket;
        bool m_running;

    public:
        // Constructor
        Remote(Configuration*, ConsoleDisplayer*);

        // Destructor
        ~Remote();

        // Methods
        int init();
        int start();
        int pause();

        static DWORD WINAPI threadLaucnher(void *p) {
            struct thread_param *obj = reinterpret_cast< struct thread_param* >(p);
            Remote *rem = obj->strt_remote;
            return rem->m_clientThread(obj->strt_socket);
        }

};

#endif // DEF_REMOTE_HPP
