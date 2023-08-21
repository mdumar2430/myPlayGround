var express = require("express");
var bodyParser = require("body-parser");
var app = express();
var urlEnc = bodyParser.urlencoded({extended:false});
app.post("/calcP", urlEnc ,function(req, res){
	var num1 = parseInt(req.body['t1']);
	var num2 = parseInt(req.body['t2']);
	var op = req.body['opr'];
	if(op=="+"){
		sum = num1+num2;
		res.send(sum+"");
	}
	if(op=="-"){
		diff = num1-num2;
		res.send(diff+"");
	}
	if(op=="*"){
		prod = num1*num2;
		res.send(prod+"");
	}
	if(op=="/"){
		quotient = num1/num2;
		res.send(quotient+"");
	}
});

app.listen(8000);
console.log("Server@8000");