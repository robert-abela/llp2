# Networking simulation

Pre-requisite: install net-tools (to get netstat) using: ```sudo apt install net-tools```

## Network tools
In this simulation we will use [netcat](https://www.sans.org/security-resources/sec560/netcat_cheat_sheet_v1.pdf) and [netstat](https://linux.die.net/man/8/netstat) to simulate client server communication. Netcat
is a networking utility that reads and writes data across network connections, which means it can act both as a client and a server. It is very powerful and we will only be using it in interactive mode, by typing the data that we want to send on the command line. 
Netstat (short for network statistics) is another powerful command line tool that records basic statistics about all network activities happening on the computer. While it has many features, it is mostly used to check which ports and addresses are currently active and what state they are in.

## Simulation description
In this simulation we will run netcat in two modes: Server (listening) and Client (connecting), together with netstat.

### Server (listening)
We will be using the following command: ```nc -l -p port``` with the command line arguments being:
*  -l: set the “listen” mode, waits for the incoming connections
*  -p port: choose the local port to listen on, e.g. **-p 9999**

### Client (connecting)
We will be using the following command: ```nc host port``` with the command line arguments being:
*  host: the computer we will connect to, in our case it will be **localhost** (your computer)
*  port: the local port the server is listening on, e.g. **9999**

### Netstat (monitoring)
We will be using the following command: ```netstat -tan | grep :port``` with the command line arguments being:
* -tan: display TCP sockets in all the states (not just connected) in numeric format (80 instead of http)
* | grep port: print only the lines that have a specific port number in them, e.g. **| grep 9999** (the port we will be monitoring)


## Simulation commands
1. Open a terminal window, set its title to **Monitoring** (Menu Terminal > Set Title...) and run the following command: ```netstat -tan | grep :9999```  
   This should not produce any output.

1. Open another terminal window, set its title to **Server** and run the following command: ```nc -l -p 9999```  
   Again there should be no output.

1. Go back to the monitoring terminal. Running the command again should produce the following:
   ```
   $ netstat -tan | grep :9999
   tcp        0      0 0.0.0.0:9999            0.0.0.0:*               LISTEN 
   ```
   This means that a TCP server is listening for connections on port 9999 from any network card available. 

1. Open a third terminal window, set its title to **Client** and run the following command: ``` nc localhost 9999```  
   This should agiain not produce any output.

1. Go back to the monitoring terminal. Running the command again should produce the following:
   ```
   $ netstat -tan | grep :9999
   tcp        0      0 0.0.0.0:9999            0.0.0.0:*               LISTEN     
   tcp        0      0 localhost:47874         localhost:9999          ESTABLISHED
   tcp        0      0 localhost:9999          localhost:47874         ESTABLISHED
   ```
   This means that a TCP server is still listening, but a connection has now been established between the client and the server (server_port = 9999, client_port = 47874). The client port is assigned by random by the OS, so your number will likely be different but it doesn't matter.

1. Switch to the client terminal, type some text and press Enter. This text will be sent to the server. 

1. Switch to the server terminal and you will see the text recieved from the client. 
   Now type some text (followed by Enter) on the server terminal and it will be sent to the client.

1. Switch to the client terminal again, and you will see the text recieved from the server. 
   Now press Ctrl+C to stop the client (the server will also stop running)

1. Finally switch to the monitoring terminal. Running the usual command again should produce the following:
   ```
   $ netstat -tan | grep :9999
   tcp        0      0 localhost:47874         localhost:9999          TIME_WAIT 
   ``` 
   This means that the established connection has been closed and the server is no longer listening. The OS is waiting for some time to pass before fully closing the server port (because it was not closed properly).

__Reference__: 
* https://ubidots.com/blog/how-to-simulate-a-tcpudp-client-using-netcat/
