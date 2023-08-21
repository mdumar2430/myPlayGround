var http = require('http');

function onRequest(req, res){
	if(req.url=='/')
		res.write('ERROR!');
	else if(req.url == '/home')
		res.write('This is Home Page');
	else if(req.url == '/contact')
		res.write('This is Contacts page');
	res.end()
}

http.createServer(onRequest).listen(8000);