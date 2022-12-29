<?php
	include("../config/koneksi.php");

	session_start();

	if($_SESSION['level'] == ""){
		header("location:../index.php");
	} else if($_SESSION['level'] == "student"){
		header("location:../student/index.php");
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
					<li class="nav-item active">
						<a class="nav-link" href="#informasi">Informasi</a>
					</li>
					<li class="nav-item">
						<a class="nav-link" href="mahasiswa/index.php">Mahasiswa</a>
					</li>
					<li class="nav-item">
						<a class="nav-link" href="jurusan/index.php">Jurusan</a>
					</li>
					<li class="nav-item">
						<a class="nav-link" href="../config/logout.php">Logout</a>
					</li>
				</ul>
			</div>
		</nav>
		<?php
			if(isset($_GET['id'])){
				$id = htmlspecialchars($_GET['id']);

				$query = "DELETE FROM informasi WHERE id='$id'";
				$hasil = mysqli_query($connection, $query);

				if($hasil){
					header("location:index.php");
				} else{
					echo "<div class='alert alert-danger mt-5'>Data Gagal dihapus!</div>";
				}
			}
		?>
		<a href="add.php" class="btn btn-primary mt-3" role="button">Tambahkan Informasi</a>
		<!-- start table -->
		<table class="table table-striped table-hover mt-3">
			<thead class="thead-dark">
		    	<tr>
					<th scope="col" style="width: 5%">No</th>
					<th scope="col" style="width: 80%">Informasi</th>
					<th scope="col" style="width: 15%">Action</th>
		    	</tr>
			</thead>
			<tbody>
				<?php
					$query = "SELECT * FROM informasi";
					$hasil = mysqli_query($connection, $query);

					$no = 0;

					while($data = mysqli_fetch_array($hasil)){
						$no++;
				?>
		    	<tr>
					<th scope="row"><?= $no; ?></th>
					<td><?= $data['info']; ?></td>
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
