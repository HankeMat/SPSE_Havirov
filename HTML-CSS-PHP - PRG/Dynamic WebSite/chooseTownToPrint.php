<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Database</title>
    <style>
        table{
            border: 5px solid black;
            text-align: center;
        }
        td{
            width: 50px;
            font-size: 18px;
        }
        .town{
            width: 200px;
        }
        th{
            font-size: 24px;
            border-bottom: 1px solid black;
        }
    </style>
</head>
<body>
    <form action="" method="post">
    <?php
        include "connection.php";
        $sqlRead = "SELECT * FROM test_table";
        $readResult = mysqli_query($connection, $sqlRead);
        echo "<select name=\"DBlist\">";
        while (list($id, $name, $surname, $age, $town, $education) = mysqli_fetch_row($readResult)) {
            echo "<option value=\"$town\">$town</option>";
        }
        echo "</select>";
    ?>
    <input type="submit" value="Find">
    </form>
    
    
    <?php
        if ($_POST) {
            echo "<table>";
            $chosen = $_POST["DBlist"];
            $readResult = mysqli_query($connection, $sqlRead);
            echo "<th>Name</th>";
            echo "<th>Surname</th>";
            echo "<th>Age</th>";
            echo "<th>Town</th>";
            echo "<th>Education</th>";
            
            while (list($id, $name, $surname, $age, $town, $education) = mysqli_fetch_row($readResult)) {
                if ($town == $chosen) {
                    echo "
                    <tr>
                    <td>$name</td>
                    <td>$surname</td>
                    <td>$age</td>
                    <td class=\"town\">$town</td>
                    <td>$education</td>
                    </tr>
                    ";
                }
            }
            mysqli_close($connection);
            echo "</table>";
        }
    ?>


</body>
</html>