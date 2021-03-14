window.onload = function(){
    const app = async () => {
        const obj = await fetch('getTelemetry.php');
        const result = await obj.json();
        console.log(result[0])
		let cpu_1 = document.querySelector('.cpu1');
		cpu_1.textContent = Math.round(result[0].CPU * 10) / 10 + '%';
		document.querySelector('#cpu_1').setAttribute("data-value", result[0].CPU);

		let temp_1 = document.querySelector('.temp1');
		temp_1.textContent = Math.round(result[0].temp * 1 )/ 1;
		let ram_1 = document.querySelector('.ram1');
		ram_1.textContent = Math.round((result[0].memUsed/4000000) * 100 )/ 1 + '%';
		
		
		
		let range_1 = document.querySelector('#range_1');
		document.querySelector('.value').textContent = Math.round(result[0].pumpSpeed * 1 )/ 1 + '%';
		let range_2 = document.querySelector('#range_2');
		document.querySelector('.value_1').textContent = Math.round(result[0].coolerSpeed * 1 )/ 1 + '%';
		
		
		
		
		
		const meters = document.querySelectorAll('svg[data-value] #meterCpu');

meters.forEach( (path) => {
  // Get the length of the path
  let length = path.getTotalLength();
  // console.log(length) once and hardcode the stroke-dashoffset and stroke-dasharray in the SVG if possible 
  // or uncomment to set it dynamically
  //path.style.strokeDashoffset = length;
  //path.style.strokeDasharray = length;

  // Get the value of the meter
  let value = parseInt(path.parentNode.getAttribute('data-value'));
  // Calculate the percentage of the total length
  let to = length * ((100 - value) / 100);
  // Trigger Layout in Safari hack https://jakearchibald.com/2013/animated-line-drawing-svg/
  path.getBoundingClientRect();
  // Set the Offset
  path.style.strokeDashoffset = Math.max(0, to);  
});

		const metersRam = document.querySelectorAll('svg[data-value] #meterRam');

metersRam.forEach( (path) => {
  // Get the length of the path
  let lengthRam = path.getTotalLength();
  // console.log(length) once and hardcode the stroke-dashoffset and stroke-dasharray in the SVG if possible 
  // or uncomment to set it dynamically
  //path.style.strokeDashoffset = length;
  //path.style.strokeDasharray = length;

  // Get the value of the meter
  // Calculate the percentage of the total length
  let toRam = lengthRam * ((100 - (Math.round((result[0].memUsed/4000000) * 100 )/ 1)) / 100);
  // Trigger Layout in Safari hack https://jakearchibald.com/2013/animated-line-drawing-svg/
  path.getBoundingClientRect();
  // Set the Offset
  path.style.strokeDashoffset = Math.max(0, toRam);  
});
		
const metersTmp = document.querySelectorAll('svg[data-value] #meterTmp');

metersTmp.forEach( (path) => {
  // Get the length of the path
  let lengthTmp = path.getTotalLength();
  // console.log(length) once and hardcode the stroke-dashoffset and stroke-dasharray in the SVG if possible 
  // or uncomment to set it dynamically
  //path.style.strokeDashoffset = length;
  //path.style.strokeDasharray = length;

  // Get the value of the meter
  // Calculate the percentage of the total length
  let toTmp = lengthTmp * ((100 - (result[0].temp)) / 100);
  // Trigger Layout in Safari hack https://jakearchibald.com/2013/animated-line-drawing-svg/
  path.getBoundingClientRect();
  // Set the Offset
  path.style.strokeDashoffset = Math.max(0, toTmp);  
});
	
	
	
	
	
	let colorPump = result[0].pumpColor;
		let [a, b, c] = colorPump.split(',');
		console.log(a);
		document.getElementById("toggler").style.color = "rgb(" +a+", "+b+", "+c+")";
		console.log(document.getElementById("toggler").style.color);
		
	let CCC = result[0].coolerColor;
		let [q, w, e] = CCC.split(',');
		console.log(q, w ,e);
		document.getElementById("toggler_1").style.color = "rgb(" +q+", "+w+", "+e+")";
		console.log(document.getElementById("toggler_1").style.color);
      }
      
	  
	  
      app()
}