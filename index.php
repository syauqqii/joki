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
	<div class="container">
		<h3 class="mt-5">
			Login - Sistem Informasi Kampus
		</h3>
		<form action="config/checker.php" method="POST" class="mt-3">
		<?php
			if(isset($_GET['pesan'])){
				if($_GET['pesan'] == "Gagal"){
					echo "<div class='alert alert-danger' role='alert'>Username / Password salah!</div>";
				}
			}
		?>
		<div class="form-group">
			<label for="username">Username</label>
			<input type="text" class="form-control" name="username" id="username" placeholder="Enter username">
		</div>
		<div class="form-group">
			<label for="password">Password</label>
			<input type="text" class="form-control" name="password" id="password" placeholder="Enter password">
		</div>
		<button type="submit" class="btn btn-primary">Login</button>
		</form>
	</div>
</body>
</html>
