<?php

global $arr;
$arr = [9,5,10,20,15,8,6];

echo "<pre>";

function fast($arr,$first,$last)
{
	global $arr;

	if($first >= $last){
		return;
	}
	$first_ex = $first;
	$last_ex = $last;

	$com = $arr[$first];

	$first_ex++;

	while ($first_ex < $last_ex) {

		while ($arr[$last_ex] >= $com && $first_ex < $last_ex) {
			
			$last_ex--;
		}
		while ($arr[$first_ex] <= $com && $first_ex < $last_ex) {
			
			$first_ex++;
		}

		if($last_ex > $first_ex){

			$temp = $arr[$last_ex];
			$arr[$last_ex] = $arr[$first_ex];
			$arr[$first_ex] = $temp;
		}
	}

// var_dump($arr,$first_ex,$last_ex);
	$temp = $arr[$last_ex];
	$arr[$last_ex] = $arr[$first];
	$arr[$first] = $temp;
	// print_r($arr);die;

	fast($arr,$first,$last_ex-1);
	fast($arr,$last_ex+1,$last);
}


fast($arr,0,count($arr)-1);


print_r($arr);