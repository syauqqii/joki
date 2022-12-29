<?php
	include("../../config/koneksi.php");

	session_start();

	if($_SESSION['level'] == ""){
		header("location:../../index.php");
	} else if($_SESSION['level'] == "student"){
		header("location:../../student/index.php");
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
		<nav class="navbar navbar-expand-lg navbar-light bg-transparant">
			<a class="navbar-brand" href="#page-top">ADMIN | Sistem Informasi Kampus</a>
			<button class="navbar-toggler navbar-toggler-right" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
				<span class="navbar-toggler-icon"></span>
			</button>
			<div class="collapse navbar-collapse" id="navbarNav">
				<ul class="navbar-nav ml-auto">
					<li class="nav-item">
						<a class="nav-link" href="../index.php">Informasi</a>
					</li>
					<li class="nav-item active">
						<a class="nav-link" href="#mahasiswa">Mahasiswa</a>
					</li>
					<li class="nav-item">
						<a class="nav-link" href="../jurusan/index.php">Jurusan</a>
					</li>
					<li class="nav-item">
						<a class="nav-link" href="../../config/logout.php">Logout</a>
					</li>
				</ul>
			</div>
		</nav>
		<?php
			if(isset($_GET['id'])){
				$id = htmlspecialchars($_GET['id']);

				$query = "DELETE FROM login WHERE id='$id' AND level='student'";
				$hasil = mysqli_query($connection, $query);

				if($hasil){
					header("location:index.php");
				} else{
					echo "<div class='alert alert-danger mt-5'>Data Gagal dihapus!</div>";
				}
			}

			if(isset($_GET['pesan'])){
				if($_GET['pesan'] == "jurusan_kosong"){
					echo "<div class='alert alert-danger mt-5'>Tambahkan jurusan dihalaman jurusan terlebih dahulu!</div>";
				}
			}
		?>
		<a href="add.php" class="btn btn-primary mt-3" role="button">Tambahkan Mahasiswa</a>
		<!-- start table -->
		<table class="table table-striped table-hover mt-3">
			<thead class="thead-dark">
		    	<tr> 
		    		<!-- id, username, password, level -->
					<th scope="col" style="width: 15%">NPM</th>
					<th scope="col" style="width: 20%">Nama Mahasiswa</th>
					<th scope="col" style="width: 20%">Jurusan</th>
					<th scope="col" style="width: 15%">Username</th>
					<th scope="col" style="width: 15%">Password</th>
					<th scope="col" style="width: 15%">Action</th>
		    	</tr>
			</thead>
			<tbody>
				<?php
					$query = "SELECT * FROM login WHERE level='student'";
					$hasil = mysqli_query($connection, $query);

					$no = 0;

					while($data = mysqli_fetch_array($hasil)){
						$no++;
				?>
		    	<tr>
					<td><?= $data['npm']; ?></td>
					<td><?= $data['nama']; ?></td>
					<td><?= $data['jurusan']; ?></td>
					<td><?= $data['username']; ?></td>
					<td><?= $data['password']; ?></td>
					<td>
						<a href="update.php?id=<?= htmlspecialchars($data['id']); ?>" class="btn btn-success btn-sm" role="button">Edit</a>
						<a href="?id=<?= htmlspecialchars($data['id']); ?>" class="btn btn-danger btn-sm" role="button">Hapus</a>
					</td>
		    	</tr>
		    	<?php } ?>
			</tbody>
		</table>
		<!-- end table -->
	</div>
	<!-- end container -->
</body>
</html>
