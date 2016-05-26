// R: following code is design to work with the Espruino boards ;)

// step1: wip code used
var IRreceiverPin = C3;
var lastTime = 0;
function onPulseOn(e){
  print( e.time - lastTime );
  lastTime = e.time;
}
function onPulseOff(e){
  lastTime = e.time;
}
setWatch(onPulseOn, IRreceiverPin, {repeat: true, edge: "falling"})
setWatch(onPulseOff, IRreceiverPin, {repeat: true, edge: "rising"})

// the following numbers can be divided in 2 groups:
// less than || greater than 0.001
0.00450420379  >0.001
0.00056076049
0.00168037414  >0.001
0.00168037414  >0.001
0.00168037414  >0.001
0.00056362152
0.00168228149  >0.001
0.00168228149  >0.001
0.00168323516  >0.001
0.00167369842  >0.001
0.00167369842  >0.001
0.00167369842  >0.001
0.00055694580
0.00055789947
0.00055885314
0.00055980682
0.00168609619  >0.001
0.00055885314
0.00055980682
0.00167942047  >0.001
0.00167942047  >0.001
0.00056171417
0.00056266784
0.00056457519
0.00056552886
0.00167465209  >0.001
0.00055599212
0.00167655944  >0.001
0.00055885314
0.00167846679  >0.001
0.00167846679  >0.001
0.00056171417
0.00168132781  >0.001


// step2: wip code used - returning either true || false
var IRreceiverPin = C3;
var lastTime = 0;
function onPulseOn(e){
  print( (e.time - lastTime)>0.001 );
  lastTime = e.time;
}
function onPulseOff(e){
  lastTime = e.time;
}
setWatch(onPulseOn, IRreceiverPin, {repeat: true, edge: "falling"})
setWatch(onPulseOff, IRreceiverPin, {repeat: true, edge: "rising"})


// step3: wip code used - save successive signals spaced by 20ms minimum as a "code"
var IRreceiverPin = C3;
var lastTime = 0;
var timeout = undefined;
var code = 0;
function handleCode(){
  timeout = undefined;
  print( code );
  code = 0;
}
function onPulseOn(e){
  //print( (e.time - lastTime)>0.001 );
  code = ( code*2 ) | ( (e.time - lastTime)>0.001 );
  if ( timeout!== undefined ) clearTimeout( timeout );
  timeout = setTimeout( handleCode, 20 ); 
  lastTime = e.time;
}
function onPulseOff(e){
  lastTime = e.time;
}
setWatch(onPulseOn, IRreceiverPin, {repeat: true, edge: "falling"});
setWatch(onPulseOff, IRreceiverPin, {repeat: true, edge: "rising"});

// -- resulting logs --
// volume down      =>  2011246765
// volume up        =>  2011254957
// previous track   =>  2011271341
// next track       =>  2011259053
// play / pause     =>  2011275437
// menu             =>  2011283629
