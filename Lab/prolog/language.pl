language(german).
language(french).
language(japanese).
study(arun, german).
study(manu, french).
study(raj, japanese).
study(vani, german).
teach(sriram,french).
teach(ragu,german).
teach(anu,japanese).
student(X,Y):-language(Z),study(X,Z),teach(Y,Z).
teacher(X,Y):-teach(X,Z),study(Y,Z),language(Z).
