var exports = {}; // added for module testing


// -- Apple Remote module --
var AppleRemote = {
// to be used as: if ( AppleRemote.codes[2011246765] !== undefined ) print ( AppleRemote.codes[2011246765] )
  codes: {
    2011246765: 'volumeDown',
    2011254957: 'volumeUp',
    2011271341: 'previousTrack',
    2011259053: 'nextTrack',
    2011275437: 'playPause',
    2011283629: 'menu'
  },
  lastTime: 0,
  timeout: undefined,
  code: 0,
  handleCode: function(){
    AppleRemote.timeout = undefined;
    // handle the Apple Remote code
    if ( AppleRemote.codes[AppleRemote.code] !== undefined ) print( AppleRemote.codes[AppleRemote.code] );
    else print( AppleRemote.code );
    AppleRemote.code = 0;
  },
  onPulseOn: function(e){
    AppleRemote.code = ( AppleRemote.code*2 ) | ( (e.time - AppleRemote.lastTime)>0.001 );
    if ( AppleRemote.timeout!== undefined ) clearTimeout( AppleRemote.timeout );
    AppleRemote.timeout = setTimeout( AppleRemote.handleCode, 20 ); 
    AppleRemote.lastTime = e.time;
  },
  onPulseOff: function(e){
    AppleRemote.lastTime = e.time;
  }
};
exports.connect = function(pin, callback) {
  setWatch(AppleRemote.onPulseOn, pin, {repeat: true, edge: "falling"});
  setWatch(AppleRemote.onPulseOff, pin, {repeat: true, edge: "rising"});
};

//require("AppleRemote").connect(C3, function(codeOrCmd) { // to be used when the module is finalized
exports.connect(C3, function(codeOrCmd) { // to be used when the module is being tested
  if (codeOrCmd=='volumeDown') print( 'volume down' );
  else if (codeOrCmd=='volumeup') print( 'volumeD up' );
  else if (codeOrCmd=='previousTrack') print( 'previous track' );
  else if (codeOrCmd=='nextTrack') print( 'next track' );
  else if (codeOrCmd=='playPause') print( 'play pause' );
  else if (codeOrCmd=='menu') print( 'menu' );
  else console.log("Unknown command: "+codeOrCmd);
});
