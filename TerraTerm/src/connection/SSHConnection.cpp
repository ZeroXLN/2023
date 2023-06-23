#include "SSHConnection.h"
#include <iostream>
#include <cstring>

SSHConnection::SSHConnection() {
    // 构造函数的实现
    m_session = ssh_new();
    if (!m_session) {
        std::cerr << "Failed to create SSH session." << std::endl;
    }
}

SSHConnection::~SSHConnection() {
    // 析构函数的实现
    disconnect();
    if (m_session) {
        ssh_free(m_session);
    }
}

void SSHConnection::connect(const std::string& hostname, int port, const std::string& username, const std::string& password) {
    // 连接SSH服务器的实现
    std::cout << "Connecting to " << hostname << ":" << port << " as " << username << "..." << std::endl;
    
    ssh_options_set(m_session, SSH_OPTIONS_HOST, hostname.c_str());
    ssh_options_set(m_session, SSH_OPTIONS_PORT, &host);
    ssh_options_set(m_session, SSH_OPTIONS_USER, username.c_str());

    int rc = ssh_connect(m_session);
    if (rc != SSH_OK) {
        std::cerr << "Failed to connect to SSH server: " << ssh_get_error(m_session) << std::endl;
        return false;
    }

    if (!verifyKnownHosts()) {
        return false;
    }

    if (!authenticatePassword(password)) {
        return false;
    }

    return true;
    
    // 连接逻辑的实现代码
}

bool SSHConnection::connectWithKey(const std::string& hostname, int port, const std::string& username, const std::string& privateKeyPath, const std::string& passphrase) {
    ssh_options_set(m_session, SSH_OPTIONS_HOST, hostname.c_str());
    ssh_options_set(m_session, SSH_OPTIONS_PORT, &port);
    ssh_options_set(m_session, SSH_OPTIONS_USER, username.c_str());

    int rc = ssh_connect(m_session);
    if (rc != SSH_OK) {
        std::cerr << "Failed to connect to SSH server: " << ssh_get_error(m_session) << std::endl;
        return false;
    }

    if (!verifyKnownHosts()) {
        return false;
    }

    if (!authenticateKey(privateKeyPath, passphrase)) {
        return false;
    }
}

void SSHConnection::disconnect() {
    // 断开SSH连接的实现
    std::cout << "Disconnecting..." << std::endl;
    // 断开连接的实现代码
}