var http = require('http');
var fs = require('fs');
function onRequest(req, res){
	res.setHeader("content-type","text/html")
	html = fs.readFileSync('./url.html')
	res.end()
}

http.createServer(onRequest).listen(8000);