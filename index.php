<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Smart Edge cluster monitoring</title>
 
    <script src="https://kit.fontawesome.com/8011d53e96.js" crossorigin="anonymous"></script>
    <link href="https://fonts.googleapis.com/css2?family=Audiowide&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="/css/main.css">
</head>
<body>
    <div class="grid-container">
        <h1>Smart Edge cluster monitoring</h1>
			
			<?php
				require_once 'db.php';
				if(isset($_GET["pumpColor"])||isset($_GET["coolerColor"])||isset($_GET["pumpSpeed"])||isset($_GET["coolerSpeed"])){
					$db = new dbInterface("frontData");
					if(isset($_GET["pumpColor"])&&$_GET["pumpColor"]!=""){
						$db->updateValue("frontData","pumpColor",substr($_GET["pumpColor"],strpos($_GET["pumpColor"],"(")+1,-1));
					}
					if(isset($_GET["coolerColor"])&&$_GET["coolerColor"]!=""){
						$db->updateValue("frontData","coolerColor",substr($_GET["coolerColor"],strpos($_GET["coolerColor"],"(")+1,-1));
					}
					if(isset($_GET["pumpSpeed"])&&$_GET["pumpSpeed"]!=""){
						$db->updateValue("frontData","pumpSpeed",$_GET["pumpSpeed"]);
					}
					if(isset($_GET["coolerSpeed"])&&$_GET["coolerSpeed"]!=""){
						$db->updateValue("frontData","coolerSpeed",$_GET["coolerSpeed"]);
					}
				}
				//include "test.php";
			?>
			
			
            <div class="rp-container_1">
                <p>#1</p>
                <i class="fab fa-raspberry-pi" ></i>
            </div>

            <div class="metricsContainer_1">
                <svg id="temp_1" xmlns="http://www.w3.org/2000/svg" height="150" width="150" viewBox="0 0 200 200" data-value="">
                    <path class="bg" stroke="#ccc" d="M41 149.5a77 77 0 1 1 117.93 0"  fill="none"/>
                    <path class="meter" id="meterTmp" stroke="#09c" d="M41 149.5a77 77 0 1 1 117.93 0" fill="none" stroke-dasharray="350" stroke-dashoffset="350"/>
                    <text x="55" y="113" class=" percents temp1" >40</text>
                    <text x="72" y="180" class="percents" >°C</text>
                  </svg>

                  <svg id="cpu_1" xmlns="http://www.w3.org/2000/svg" height="150" width="150" viewBox="0 0 200 200" data-value="">
                    <path class="bg" stroke="#ccc" d="M41 149.5a77 77 0 1 1 117.93 0"  fill="none"/>
                    <path class="meter" id="meterCpu" stroke="#09c" d="M41 149.5a77 77 0 1 1 117.93 0" fill="none" stroke-dasharray="350" stroke-dashoffset="350"/>
                    <text x="55" y="113" class="percents cpu1" >40%</text>
                    <text x="52" y="180" class="percents" >CPU</text>
                    
                  </svg>

                  <svg id="ram_1" xmlns="http://www.w3.org/2000/svg" height="150" width="150" viewBox="0 0 200 200" data-value="">
                    <path class="bg" stroke="#ccc" d="M41 149.5a77 77 0 1 1 117.93 0"  fill="none"/>
                    <path class="meter" id="meterRam" stroke="#09c" d="M41 149.5a77 77 0 1 1 117.93 0" fill="none" stroke-dasharray="350" stroke-dashoffset="350"/>
                    <text x="55" y="113" class="percents ram1" >40%</text>
                    <text x="50" y="180" class="percents" >RAM</text>
                  </svg>
            </div>

          
           
          

                <div class="pomp-block">
                  <a href="#" id="toggler" onclick="document.getElementById('myform').submit(); return false;"><i class="fas fa-database"></i></a>
                 
                  <div class="power-block">
                    <form action="index.php" method="get" id="myform">
					<input id="setValue" type="text" name="method" value="setValue">
                      <div class="value">20%</div>
                      <input name="pumpSpeed" type="range" min="20" max="100" step="1" value="<?php
					  require_once 'db.php';
					  $db = new dbInterface("frontData");
					  echo $db->selectValue("frontData","pumpSpeed");?>"id="range_1">
                      <label for="range_1">POW &</label>
                      <input id="pumpColor" name="pumpColor" type="text" value=""> 
                      <label for="colorWell">Color:</label>
                      <input type="color" value="<?php
					  require_once 'db.php';	
					  $db = new dbInterface("frontData");
					  $rgbarr = explode(",",$db->selectValue("frontData","pumpColor"),3);
					  echo sprintf("#%02x%02x%02x", $rgbarr[0], $rgbarr[1], $rgbarr[2]);?>" id="colorWell">
                    </form>
                    
                    <div class="clrPick" id="box">
                      <div id="picker"></div>
                      <div id="slider"></div>
                      
                    </div>
                  </div>
                </div>


                <div class="fan-block" class="fan-input">
                  <a href="#" id="toggler_1" onclick="document.getElementById('myform_2').submit(); return false;"><i class="fas fa-fan"></i></i></a>

                    <div class="spins-block">
                    <form action="index.php" method="get" id="myform_2">
                      <div class="value_1">20%</div>
                      <input name="coolerSpeed" type="range" min="20" max="100" step="1" value="<?php
					  require_once 'db.php';
					  $db = new dbInterface("frontData");
					  echo $db->selectValue("frontData","coolerSpeed");?>"id="range_2">
                      <label for="range_2">SPINS &</label>
                      <input id="coolerColor" name="coolerColor" type="text" value=""> 
                      <input id="setValue" type="text" name="method" value="setValue">
                      <label for="colorWell">Color:</label>
                      <input type="color" value="<?php
					  require_once 'db.php';
					  $db = new dbInterface("frontData");
					  $rgbarr = explode(",",$db->selectValue("frontData","coolerColor"),3);
					  echo sprintf("#%02x%02x%02x", $rgbarr[0], $rgbarr[1], $rgbarr[2]);?>" id="colorWell_1">
                    </form>

                    <div class="clrPick" id="box_1">
                      <div id="picker_1"></div>
                      <div id="slider_1"></div>
                    </div>
                    
                </div>

                </div>


        
        </div>
		<script src="/js/progress.js"></script>
		
		<script src="/js/display.js"></script>
        <script src="/js/colorpicker.js"></script>
        <script src="/js/slider.js"></script>
        
        
</body>
</html>