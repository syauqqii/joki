<?php
	include("koneksi.php");

	session_start();

	$username = $_POST['username'];
	$password = $_POST['password'];

	$login = mysqli_query($connection, "SELECT * FROM login WHERE username='$username' AND password='$password'");

	if(mysqli_num_rows($login) > 0){
		$data = mysqli_fetch_assoc($login);

		if($data['level'] == "admin"){
			$_SESSION['username'] = $username;
			$_SESSION['level'] = "admin";
			header("location:../admin/index.php");
		} else if($data['level'] == "student"){
			$_SESSION['username'] = $username;
			$_SESSION['level'] = "student";
			header("location:../student/index.php");
		} else{
			header("location:../index.php?pesan=Gagal");
		}
	} else{
		header("location:../index.php?pesan=Gagal");
	}
?>
