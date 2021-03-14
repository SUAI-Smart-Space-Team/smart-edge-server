var colorWell;
var colorWell_1;


window.addEventListener("load", startup, false);
window.addEventListener("load", startupsec, false);

function startup() {
  colorWell = document.querySelector("#colorWell");
  colorWell.addEventListener("input", updateFirst, false);
  colorWell.select();
}

function startupsec() {
    colorWell_1 = document.querySelector("#colorWell_1");
    colorWell_1.addEventListener("input", updateSecond, false);
    colorWell_1.select();
}

function updateFirst(event) {
  var p = document.querySelector("#toggler");
  if (p) {
    p.style.color = event.target.value;
    document.getElementById('pumpColor').value = p.style.color;
	
  }
}

function updateSecond(event) {
    var q = document.querySelector("#toggler_1");
    if (q) {
      q.style.color = event.target.value;
      document.getElementById('coolerColor').value = q.style.color;
    }
  }


