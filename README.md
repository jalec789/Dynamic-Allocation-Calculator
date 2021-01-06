#Description

####Introduction
Hello, I am Jason Chan. This is a showcase project I like to use to demonstrate not only my skill in programming but also demonstrating my early formatting disipline and capabilities. This project was created in 2017 and I have come a long way so this project doesn't represent my current abilities.

####What does it do?
This is a dynamically allocated calculator. Utilizing stack memory this calculator stores 1 byte digits and can allocate input based on the size of the stack. Simply said this calculator allows one to input numbers that traditional calculators would have a hard time storing, surpassing the input size of even Windows10's native calculator as of 2021.

####What technologies are used?
Well this program is pretty simple, just make sure you have c++ installed. The makefile simply uses `g++ -g` to compile.

####Ambition
This tech could go beyond towards creating a hefty calculator.

####Current Stage
This calculator currently only takes 2 inputs and displays one output but this could go on to become bigger than what it already is.

####Issues and Plans
- Currently there is an issue with letter input that would be an easy fix.
- If adding more functionality to this project, maybe try taking output as input for next operations.
- Division functionality
- Unit testing

#How to Run
The makefile has information to run the program but the quick and easy version is here. In the terminal, navigate to the directory containing all files. Then compile with...
`make all`
And run with...
`./hw09`
From here you are prompted with a menu.
`1`
to enter numbers and your first number can be 3, and second number can be 2. Now you add, subtract or multiply these numbers in the menu with `2` `3` `4`. But that is not very exciting...

For our first number let's mash the number keypad with a random large value:
1938475987491083471938471934875981734981374190834719814951947198798798175987598234757264857624876757868173469140585797109871018749187481723498173461786716387461873461874187461837468176481765759357092845729487594875918391873498173947193471983479183749187917598749817349817487184787187489188179587198749182374918749182749287491283413841348713094813948139475858851818817

And our second number be:
18018491801841128438903982080943298341294319049940419498189494198328148757527457235746654615635163546131546123478365935867459687984572349720148307491837236587246556045823459234858947528947598740878730841783471837817587458719837491087341093847918347198374985687647816347864157143612305305872485720741873481740817384785748562465048160384103984719837598759817439871394873894710349817349813498173409187458686816384613646412874613876716481647614761374613754058396986875857874857857843464626515524514144143131231384095803950395809809645098059

And yes I just mashed the number keypad but seriously try to add, subtract, and multiply these. watch out for letters they will cutoff the number value up to the letter. Test it out. Try to break the upper limit of the stack and send me an issue if you reach it. Have Fun. Press `6` in the menu to exit.
