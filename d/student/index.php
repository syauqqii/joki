<?php
	include("../config/koneksi.php");

	session_start();

	if($_SESSION['level'] == ""){
		header("location:../index.php");
	} else if($_SESSION['level'] == "admin"){
		header("location:../admin/index.php");
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
		<h3 class="mt-5">
			Mahasiswa | Sistem Informasi Kampus
		</h3>
		<!-- start table -->
		<a href="../config/logout.php" class="btn btn-info mt-3" role="button">Logout</a>
		<!-- start table -->
		<table class="table table-striped table-hover mt-3">
			<thead class="thead-dark">
		    	<tr>
					<th scope="col" style="width: 5%">No</th>
					<th scope="col" style="width: 95%">Informasi</th>
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
		    	</tr>
		    	<?php } ?>
			</tbody>
		</table>
		<!-- end table -->
	</div>
	<!-- end container -->
</body>
</html>
