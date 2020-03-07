<?php


$arr = [1,2,3,4,5,6,7];


function test($arr, $n)
{

	if($n < 0){
		return;
	}

	// echo $arr[$n].',';

	test($arr, $n-1);

	echo $arr[$n].',';
}


test($arr, 6);

die;
 function chkurl($url){
    $handle = curl_init($url);
    curl_setopt($handle, CURLOPT_RETURNTRANSFER, TRUE);
    curl_setopt($handle, CURLOPT_CONNECTTIMEOUT, 10);//设置超时时间
    curl_exec($handle);
    //检查是否404（网页找不到）
    $httpCode = curl_getinfo($handle, CURLINFO_HTTP_CODE);
    print_r($httpCode);die;


    curl_close($handle);
        if($httpCode == 404) {
      return false;
    }else{
        return true;
    }
 }
 $url="https://user-czy.colourlife.com/images/icon_head.png";
  // $url="https://cimg.colourlife.com/images/2019/03/30/09/380258481.jpg";
 // if(chkurl($url)==true){
 //     echo "存在";
 // }else{
 //     echo "不存在";
 // }



$headers = get_headers($url);
 
if (strpos($headers[0], '404')) 
{echo "404";}else{
 echo '正常访问';
}
die;


$arr = [1,2,3,4,5,6];

$a=0;
$b=0;
while ($arr[$a] != 5) {
	echo $arr[$a];

	$a++;
}
echo "<pre><br>";
echo $a;