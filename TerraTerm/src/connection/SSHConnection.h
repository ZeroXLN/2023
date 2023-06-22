#ifndef SSHCONNECTION_H
#define SSHCONNECTION_H

#include <string>

class SSHConnection {
    public:
        SSHConnection();
        ~SSHConnection();

        void connect(const std::string& hostname, int port, const std::string& username, const std::string& password);

};

#endif // SSHCONNECTION_H