from http.server import BaseHTTPRequestHandler, HTTPServer
from pathlib import Path
import subprocess as sub

class MyRequestHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        print ("SERVER: I got a GET request.")
        if self.path == '/':
            file_path = Path(__file__).parent / 'client.html'
            if file_path.exists() and file_path.is_file():
                self.send_response(200)
                self.send_header('Content-type', 'text/html')
                self.end_headers()
                with open(file_path, 'rb') as file:
                    self.wfile.write(file.read())
            else:
                self.send_response(404)
                self.end_headers()
                self.wfile.write(b'File Not Found')
        elif self.path == '/opponentPlay':
            self.send_response(200)
            self.send_header('Content-type', 'text/plain')
            self.end_headers()
            sub.run("./Chess", shell=True)
            file = open("position.txt", "r")
            message = file.read()
            self.wfile.write(message.encode())
        elif self.path == '/getMoves':
            self.send_response(200)
            self.send_header('Content-type', 'text/plain')
            self.end_headers()
            sub.run("./GetMoves", shell=True)
            file = open("selectPawns.txt", "r")
            message = file.read()
            self.wfile.write(message.encode())
        else:
            self.send_response(404)
            self.end_headers()
            self.wfile.write(b'Not Found')

    def do_POST(self):
        print ("SERVER: I got a POST request.")
        if self.path == '/pos':
            content_length = int(self.headers['Content-Length'])
            post_data_bytes = self.rfile.read(content_length)
            post_data_str = post_data_bytes.decode()
            file = open("position.txt", "w")
            file.write(post_data_str)
            file.close()
        elif self.path == '/selectPawn':
            content_length = int(self.headers['Content-Length'])
            post_data_bytes = self.rfile.read(content_length)
            post_data_str = post_data_bytes.decode()
            file = open("selectPawns.txt", "w")
            file.write(post_data_str)
            file.close()

def run(server_class=HTTPServer, handler_class=MyRequestHandler, port=8000):
    server_address = ('127.0.0.1', port)
    httpd = server_class(server_address, handler_class)
    print(f"Server listening on {server_address}")
    httpd.serve_forever()

if __name__ == '__main__':
    run()
