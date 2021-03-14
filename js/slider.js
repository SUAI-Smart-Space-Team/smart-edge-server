var slide = document.querySelector('div.power-block input[type="range"]');

var rangeValue = function(){
  var newValue = slide.value;
  var target = document.querySelector('.value');
  target.innerHTML = newValue + "%";
}

slide.addEventListener("input", rangeValue);

var slide_1 = document.querySelector('div.spins-block input[type="range"]');

var rangeValue_1 = function(){
  var newValue_1 = slide_1.value;
  var target_1 = document.querySelector('.value_1');
  target_1.innerHTML = newValue_1 + "%";
}

slide_1.addEventListener("input", rangeValue_1);