<?php
	include("../../config/koneksi.php");

	session_start();

	if($_SESSION['level'] == ""){
		header("location:../../index.php");
	} else if($_SESSION['level'] == "student"){
		header("location:../../student/index.php");
	}

	function input($data){
		$data = trim($data);
		$data = stripslashes($data);
		$data = htmlspecialchars($data);

		return $data;
	}
?>

<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	
	<!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.3.1/dist/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">

	<title>Sistem Informasi Kampus</title>
</head>
<body>
	<!-- start container -->
	<div class="container">
		<h3 class="mt-5">Admin | Tambahkan Jurusan</h3>
		<?php
			if(isset($_POST['jurusan'])){
				$jurusan = input($_POST['jurusan']);

				$query = "INSERT INTO jurusan VALUES ('','$jurusan')";

				if(mysqli_query($connection, $query)){
					header("location:index.php");
				} else{
					echo "<div class='alert alert-danger mt-3'>Data Gagal disimpan!</div>";
				}
			}
		?>
		<form action="" method="POST">
			<div class="form-group mt-3">
				<label for="Jurusan">Jurusan :</label>
    			<input type="text" class="form-control" name="jurusan" id="Jurusan" placeholder="Input Jurusan">
			</div>
			<button type="submit" class="btn btn-primary">Tambahkan</button>
			<a href="index.php" class="btn btn-danger" role="button">Batal</a>
		</form>
	</div>
	<!-- end container -->
</body>
</html>
