# My_FTP 🗄

Welcome to **My_FTP**.

This project is dedicated to creating a fully functional File Transfer Protocol (FTP) server, following the standard FTP protocol as outlined in RFC 959.

## Language and Tools 🛠️

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

- **Language:** C
- **Compilation:** Via Makefile, including `re`, `clean`, and `fclean` rules.
- **Binary Name:** myftp

## Project Overview 🔎

The goal of my FTP is to build an FTP server capable of handling multiple client connections simultaneously.

The server should support essential FTP commands and adhere to the FTP protocol, enabling file transfers and basic file system operations.

### Key Features

- **Multi-Client Support:** Handle several clients concurrently using `select` for command management and `fork` for data transfers.
- **FTP Protocol Compliance:** Implement FTP protocol requirements, including authentication, active/passive data transfer modes, and standard command sequences.
- **Anonymous Authentication:** Include authentication for an Anonymous user account with an empty password.
- **Path Management:** Specify a home directory for the Anonymous user.

### Usage

```
./myftp port path
    port    is the port number on which the server socket listens
    path    is the path to the home directory for the Anonymous user
```

### Running the Server

To get your FTP server up and running, follow these steps:

1. **Compile the Server:**
   - Navigate to the root directory of the project where the Makefile is located.
   - Run the command `make` to compile the server. This will create the `myftp` executable.

2. **Start the Server:**
   - Launch the server by running `./myftp <port> <path>`.
   - Replace `<port>` with the port number you want the server to listen on.
   - Replace `<path>` with the absolute path to the home directory for the Anonymous user.

3. **Connect to the Server:**
   - Use any standard FTP client software.
   - Connect to the server using its IP address and the port number you specified when starting the server.
   - Log in as an Anonymous user or as a registered user if your server supports user accounts.

4. **Using the Server:**
   - Once connected, you can start using FTP commands to navigate the directory, upload, download, or manage files as per your server's capabilities and user permissions.

5. **Shutting Down the Server:**
   - To stop the server, simply terminate the process in your terminal. This can usually be done by pressing `Ctrl + C`.

**Note:** Ensure that the server has the necessary permissions to access and modify the specified home directory. Also, make sure the specified port is open and not blocked by any firewalls or network configurations.


## Installation and Usage 💾

1. Clone the repository.
2. Compile the program using the provided Makefile.
3. Run the the server.
4. For detailed guidelines, refer to `myftp.pdf`.


## License ⚖️

This project is released under the MIT License. See `LICENSE` for more details.
