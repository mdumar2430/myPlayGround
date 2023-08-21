import { ComponentFixture, TestBed } from '@angular/core/testing';

import { EbindComponent } from './ebind.component';

describe('EbindComponent', () => {
  let component: EbindComponent;
  let fixture: ComponentFixture<EbindComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ EbindComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(EbindComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
