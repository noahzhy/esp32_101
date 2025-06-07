from http.server import BaseHTTPRequestHandler, HTTPServer
import socket
from urllib.parse import parse_qs

# ESP32 IP address and port
ESP32_IP = "192.168.0.233"  # Change to your ESP32 IP
ESP32_PORT = 3600            # Port number

class SimpleHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        # Serve a simple HTML form for user input
        if self.path == "/" or self.path == "/index.html":
            self.send_response(200)
            self.send_header('Content-type', 'text/html')
            self.end_headers()
            html = """
            <html>
                <head><title>ESP32 TCP Test</title></head>
                <body>
                    <h2>Send message to ESP32</h2>
                    <form method="POST">
                        <input name="msg" placeholder="Enter message">
                        <button type="submit">Send</button>
                    </form>
                </body>
            </html>
            """
            self.wfile.write(html.encode('utf-8'))
        else:
            # Return 404 for other paths
            self.send_error(404, "File Not Found")

    def do_POST(self):
        # Handle form submission and send message to ESP32 via UDP
        content_length = int(self.headers.get('Content-Length', 0))
        post_data = self.rfile.read(content_length).decode('utf-8')
        params = parse_qs(post_data)
        msg = params.get('msg', [''])[0]

        # Send the message to ESP32 using UDP
        result = ""
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
                s.sendto(msg.encode(), (ESP32_IP, ESP32_PORT))
            result = f"Sent (UDP): {msg}"
        except Exception as e:
            result = f"Send failed: {e}"

        # Respond with result and a link to return, show result as a small tip on the same page
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()
        html = f"""
        <html>
            <head><title>ESP32 UDP Test</title></head>
            <body>
                <h2>Send message to ESP32</h2>
                <form method="POST">
                    <input name="msg" placeholder="Enter message">
                    <button type="submit">Send</button>
                </form>
                <div style='color: #888; font-size: 0.9em; margin-top: 1em;'>
                    {result}
                </div>
            </body>
        </html>
        """
        self.wfile.write(html.encode('utf-8'))

if __name__ == "__main__":
    # Start the HTTP server on localhost:8000
    server = HTTPServer(('localhost', 8000), SimpleHandler)
    print("Server running at http://localhost:8000")
    server.serve_forever()