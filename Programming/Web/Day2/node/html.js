var http = require('http');

function onRequest1(req, res){
	res.setHeader("content-type", "text/html");
	res.write('<h1><i>UMAR</i></h1>');
	res.end();
}
function onRequest2(req, res){
	res.write('<h1><i>hello</i></h1>');
	res.end();
}
http.createServer(onRequest1).listen(8080);
http.createServer(onRequest2).listen(8082);