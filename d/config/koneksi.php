<?php 

	$address  = 'localhost';
	$username = 'root';
	$password = '';
	$database = 'sistem_informasi';

	$connection = mysqli_connect($address, $username, $password, $database);

	if(mysqli_connect_errno()){
		echo "Koneksi databse gagal : " . mysqli_connect_error();
	}
?>
