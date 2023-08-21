var http= require('http');
var url = require("url");
var querystring = require("querystring");

var server = http.createServer(function(req, res){
	res.setHeader("content-type","text/html");
	var purl = url.parse(req.url);
	var qs = querystring.parse(purl.query);
	var a= parseInt(qs.t1);
	var b= parseInt(qs.t2);
	
	if(qs.opr=="+"){
		sum = a+b;
		res.write(sum+"");
	}
	if(qs.opr=="-"){
		diff = a-b;
		res.write(diff+"");
	}
	if(qs.opr=="*"){
		prod = a*b;
		res.write(prod+"");
	}
	if(qs.opr=="/"){
		quotient = a/b;
		res.write(quotient+"");
	}
	res.end();
});
server.listen(8000);
console.log("Server@8000");