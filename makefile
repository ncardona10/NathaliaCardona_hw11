phase.png pos.png vel.png: tray.txt
	python NC_graph.py

tray.txt:
	g++ NC_gravity.cpp -o gravity 
	./gravity > tray.txt

clean:
	rm *.png
	rm tray.txt