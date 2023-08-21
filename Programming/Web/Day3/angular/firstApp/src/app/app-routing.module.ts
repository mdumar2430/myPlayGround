import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { CalcComponent } from './calc/calc.component';
import { CrudComponent } from './crud/crud.component';
import { DBindComponent } from './d-bind/d-bind.component';
import { DirectiveComponent } from './directive/directive.component';
import { EBindComponent } from './e-bind/e-bind.component';
import { PipeComponent } from './pipe/pipe.component';
import { TwowayComponent } from './twoway/twoway.component';
import { WelcomeComponent } from './welcome/welcome.component';

const routes: Routes = [
  {path:"Welcome",component:WelcomeComponent},
  {path:"Dbind",component:DBindComponent},
  {path:"Ebind",component:EBindComponent},
  {path:"Twoway",component:TwowayComponent},
  {path:"Pipe",component:PipeComponent},
  {path:"Calc",component:CalcComponent},
  {path:"Directive",component:DirectiveComponent},
  {path:"Crud",component:CrudComponent}

];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
