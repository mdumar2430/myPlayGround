import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'boostlen'
})
export class BoostlenPipe implements PipeTransform {

  transform(value: string, num:number=5, num2:number): number {
    return value.length+num+num2;
  }

}
