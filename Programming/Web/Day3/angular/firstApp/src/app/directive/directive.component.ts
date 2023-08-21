import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-directive',
  templateUrl: './directive.component.html',
  styleUrls: ['./directive.component.css']
})
export class DirectiveComponent implements OnInit {

  constructor() { }
  show:boolean=true;
  bname:string="Hide";
  movielist:string[]=["Manmadhan","Asuran"];
  showHidetext(){
    if(this.bname=="Show"){
      this.show=true;
      this.bname="Hide";
    }
    else if(this.bname=="Hide"){
      this.show=false;
      this.bname="Show";
    }
  }
  size:number=30;
  ngOnInit(): void {
  }

}
