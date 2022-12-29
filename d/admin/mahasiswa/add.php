<?php
	include("../../config/koneksi.php");

	session_start();

	if($_SESSION['level'] == ""){
		header("location:../../index.php");
	} else if($_SESSION['level'] == "student"){
		header("location:../../student/index.php");
	}

	$req = mysqli_query($connection, "SELECT * FROM jurusan");
	$res = mysqli_fetch_array($req, MYSQLI_ASSOC);

	if(!isset($res['jurusan'])){
		header("location:index.php?pesan=jurusan_kosong");
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
		<h3 class="mt-5">Admin | Tambahkan Mahasiswa</h3>
		<?php
			if(isset($_POST['npm'])){
				$npm = input($_POST['npm']);
				$nama = input($_POST['nama']);
				$jurusan = input($_POST['jurusan']);
				$username = input($_POST['username']);
				$password = input($_POST['password']);

				$query = "INSERT INTO login VALUES ('','$npm','$nama','$jurusan','$username','$password','student')";

				if(mysqli_query($connection, $query)){
					header("location:index.php");
				} else{
					echo "<div class='alert alert-danger mt-3'>Data Gagal disimpan!</div>";
				}
			}
		?>
		<form action="" method="POST">
			<div class="form-group mt-3">
				<label for="npm">NPM :</label>
    			<input type="text" class="form-control" name="npm" id="npm" placeholder="Input npm">
			</div>
			<div class="form-group">
				<label for="nama">Nama Mahasiswa :</label>
    			<input type="text" class="form-control" name="nama" id="nama" placeholder="Input nama">
			</div>
			<div class="form-group">
				<label for="jurusan">Jurusan :</label>
				<select class="custom-select" id="jurusan" name="jurusan">
					<?php $hsl = mysqli_query($connection, "SELECT * FROM jurusan"); while($hasil = mysqli_fetch_array($hsl)){ echo $hasil; ?>
				    <option value="<?= $hasil['jurusan']; ?>"><?= $hasil['jurusan']; ?></option>
					<?php } ?>
				</select>
			</div>
			<div class="form-group">
				<label for="username">Username :</label>
    			<input type="text" class="form-control" name="username" id="username" placeholder="Input username">
			</div>
			<div class="form-group">
				<label for="password">Password :</label>
    			<input type="text" class="form-control" name="password" id="password" placeholder="Input password">
			</div>
			<button type="submit" class="btn btn-primary">Tambahkan</button>
			<a href="index.php" class="btn btn-danger" role="button">Batal</a>
		</form>
	</div>
	<!-- end container -->
</body>
</html>
