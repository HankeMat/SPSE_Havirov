<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Delete</title>
</head>
<body>
    <form action="" method="post">
    <?php
        include "connection.php";
        $sqlRead = "SELECT * FROM test_table";
        $readResult = mysqli_query($connection, $sqlRead);
        echo "<select name=\"DBlist\">";
        while (list($id, $name, $surname, $age, $town, $education) = mysqli_fetch_row($readResult)) {
            echo "<option value=\"$id\">$id - $surname</option>";
        }
        echo "</select>";
    ?>
    <input type="submit" value="Delete">
    </form>

    <?php
        if ($_POST) {
            $matching = $_POST["DBlist"];
            $readResult = mysqli_query($connection, $sqlRead);
        
            while (list($id, $name, $surname, $age, $town, $education) = mysqli_fetch_row($readResult)) {
                $sqlDelete = "DELETE FROM test_table where id=\"$matching\"";
                mysqli_query($connection, $sqlDelete);
                if ($id == $matching) {
                    echo "Deleted!";
                }
            }
            mysqli_close($connection);
        }
    ?>

</body>
</html>