import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-e-bind',
  templateUrl: './e-bind.component.html',
  styleUrls: ['./e-bind.component.css']
})
export class EBindComponent implements OnInit {

  constructor() { }

  ngOnInit(): void {
  }
  name:string="";
  myfunc() {
    var a:any= document.getElementById("t1");
    this.name= a.value;
  }
  sz:number = 40;
  zoomIn(){
    this.sz=this.sz+5;

  }
  zoomOut(){
    this.sz=this.sz-5;
    //this.size= this.sz+"px";

  }

}
