var http = require('http');
var server = http.createServer(function(req, res){
	res.write('hai');
	res.end();
} );

server.listen(5000);
console.log("Node.js web server is running at 5000");