var http= require('http');
var url = require("url");
var querystring = require("querystring");

var server = http.createServer(function(req, res){
	res.setHeader("content-type","text/html");
	var purl = url.parse(req.url);
	var qs = querystring.parse(purl.query);
	var a= qs.t1;
	var b= qs.t2;
	res.write(a+"<br/>");
	res.write(b+"<br/>");
	res.end();
});
server.listen(8000);
console.log("Server@8000");