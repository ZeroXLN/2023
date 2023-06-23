#ifndef SSHCONNECTION_H
#define SSHCONNECTION_H

#include <libssh/libssh.h>
#include <string>
#include <vector>

class SSHConnection {
    public:
        SSHConnection();
        ~SSHConnection();

        void connect(const std::string& hostname, int port, const std::string& username, const std::string& password);
        bool connectWithKey(const std::string& hostname, int port, const std::string& username, const std::string& privateKeyPath, const std::string& passphrase);
        void disconnect();

        bool executeCommand(const std::string& command, std::string& output);
        bool startShell(std::string& output);
        bool sendShellCommand(const std::string& command, std::string& output);
        void closeShell();

        // 更多的SSH连接相关功能可在此处添加

    private:
        // 内部实现细节可在此处添加
        ssh_session m_session;
        ssh_channel m_channel;

        bool authenticatePassword(const std::string& password);
        bool authenticateKey(const std::string& privateKeyPatg, const std::string& passphrase);
        bool verifyKnownHosts();
};

#endif // SSHCONNECTION_H