<?php
/*asdfasd 

 */
 $k = 1;
 
 if(isset($kk)){
	print("isset ok\n");
 }else{
	print("isset not ok\n");
 }
 function Fibonacci($a)
 {
	$b = 1;
	global $k;
	//print("local variable $b=".$b."\n");
	//print("global variable $k=".$k."\n");
	//print($k."\n");
	if($a<0){
		$a = 0;
	}
	switch($a)
	{
		case 1:
			return 1;
		case 0: 	
			return 1;
		default:
			break;
	}
	return Fibonacci($a-1) + Fibonacci($a-2);	
 }
 
$c =11;
$fib = array(1=>"1",1=>"1",2=>"2", 3=>"3", 5=>"5", 8=>"8", 13=>"13", 21=>"21", 34=>"34", 55=>"55", 89=>"89", 144=>"144", 233=>"233",);
$b= Fibonacci($c);
print("fibonacci(".$c.") is ".$fib[$b]."\n");
$c = base64_decode("aGVsbG8=");
print($c."\n");
return 0;
?>



hello  world