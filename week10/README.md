# Networking simulation

Pre-requisite: install net-tools (to get netstat) using the following command:  
```sudo apt install net-tools```

## Network tools
In this simulation we will use [netcat](https://www.sans.org/security-resources/sec560/netcat_cheat_sheet_v1.pdf) and [netstat](https://linux.die.net/man/8/netstat) to simulate client server communication. Netcat
is a networking utility that reads and writes data across network connections, which means it can act both as a client and a server. It is very powerful and we will only be using it in interactive mode, by typing the data that we want to send on the command line. 
Netstat (short for network statistics) is another powerdful command line tool that records basic statistics on all network activities happening on the computer. While it has many features, it is mostly used to check which ports and addresses are currently active and what state they are in.

## The simulation
In this simulation we will run netcat in two modes: Server (listening) and Client (connecting).

### Server (listening)
We will be using the following command: ```nc -l -p port``` with the parameters command line arguments being:
*  -l: set the “listen” mode, waits for the incoming connections
*  -p port: choose the local port to listen on, e.g. **-p 9999**

### Client (connecting)
We will be using the following command: ```nc host port``` with the parameters command line arguments being:
*  host: the computer we will connect to, in our case it will be **localhost** (your computer)
*  port: the local port the server is listening on, e.g. **9999**


__Original Article__: 
* https://ubidots.com/blog/how-to-simulate-a-tcpudp-client-using-netcat/
