var http = require('http');

function onRequest1(req, res){
	res.write('hai');
	res.end();
}
function onRequest2(req, res){
	res.write('hello');
	res.end();
}
http.createServer(onRequest1).listen(8080);
http.createServer(onRequest2).listen(8082);