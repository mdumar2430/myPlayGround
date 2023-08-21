import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-ebind',
  templateUrl: './ebind.component.html',
  styleUrls: ['./ebind.component.css']
})
export class EbindComponent implements OnInit {

  constructor() { }

  ngOnInit(): void {
  }
  wish:string="";
  myfunc(){
    var a:any= document.getElementById("tb1");
    this.wish="Happy Birthday "+a.value;
  }
  
}
