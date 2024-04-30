<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Edit</title>
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
    <input type="submit" value="Edit" name="editBtn">
    </form>

    <?php
        if (isset($_POST["editBtn"])) {
            $matched = $_POST["DBlist"];
            $readResult = mysqli_query($connection, $sqlRead);

            while (list($id, $name, $surname, $age, $town, $education) = mysqli_fetch_row($readResult)) {
                if ($id == $matched) {
                    echo "
                    <form action=\"\" method=\"post\">
                    
                    <h2>Edit:</h2>
                    <input type=\"number\" name=\"id\" value=\"$id\" hidden>

                    <input type=\"text\" name=\"newName\" value=\"$name\" required><br>
                    <input type=\"text\" name=\"newSurname\" value=\"$surname\"><br>
                    <input type=\"number\" name=\"newAge\" value=\"$age\" max=\"100\" min=\"1\" required><br>
                    
                    <select name=\"newTown\" value=\"$town\">
                        <option value=\"Praha\">Praha</option>
                        <option value=\"Brno\">Brno</option>
                        <option value=\"Ostrava\">Ostrava</option>
                        <option value=\"Plzeň\">Plzeň</option>
                        <option value=\"Liberec\">Liberec</option>
                        <option value=\"Olomouc\">Olomouc</option>
                        <option value=\"Ústí nad Labem\">Ústí nad Labem</option>
                        <option value=\"Hradec Králové\">Hradec Králové</option>
                        <option value=\"České Budějovice\">České Budějovice</option>
                        <option value=\"Pardubice\">Pardubice</option>
                        <option value=\"Havířov\">Havířov</option>
                        <option value=\"Zlín\">Zlín</option>
                        <option value=\"Kladno\">Kladno</option>
                        <option value=\"Most\">Most</option>
                        <option value=\"Karviná\">Karviná</option>
                        <option value=\"Opava\">Opava</option>
                        <option value=\"Frýdek-Místek\">Frýdek-Místek</option>
                        <option value=\"Jihlava\">Jihlava</option>
                        <option value=\"Teplice\">Teplice</option>
                        <option value=\"Děčín\">Děčín</option>
                        <option value=\"Chomutov\">Chomutov</option>
                        <option value=\"Přerov\">Přerov</option>
                        <option value=\"Mladá Boleslav\">Mladá Boleslav</option>
                        <option value=\"Prostějov\">Prostějov</option>
                        <option value=\"Písek\">Písek</option>
                        <option value=\"Tábor\">Tábor</option>
                        <option value=\"Trutnov\">Trutnov</option>
                        <option value=\"Cheb\">Cheb</option>
                        <option value=\"Vsetín\">Vsetín</option>
                        <option value=\"Kroměříž\">Kroměříž</option>
                        <option value=\"Uherský Brod\">Uherský Brod</option>
                        <option value=\"Litvínov\">Litvínov</option>
                        <option value=\"Nový Jičín\">Nový Jičín</option>
                        <option value=\"Hodonín\">Hodonín</option>
                        <option value=\"Chrudim\">Chrudim</option>
                        <option value=\"Šumperk\">Šumperk</option>
                        <option value=\"Uherské Hradiště\">Uherské Hradiště</option>
                        <option value=\"Jablonec nad Nisou\">Jablonec nad Nisou</option>
                        <option value=\"Kutná Hora\">Kutná Hora</option>
                        <option value=\"Náchod\">Náchod</option>
                    </select>
                    <br>
                    <label for=\"newEducation\">University</label>
                    <input type=\"radio\" name=\"newEducation\" value=\"University\"><br>
                    <label for=\"newEducation\">High</label>
                    <input type=\"radio\" name=\"newEducation\" value=\"High\"><br>
                    <label for=\"newEducation\">Elementary</label>
                    <input type=\"radio\" name=\"newEducation\" value=\"Elementary\"><br>
                    ";
                }
            }
            echo "<input type=\"submit\" value=\"Submit\" name=\"submitBtn\">";
            echo "</form>";
        }

        if (isset($_POST["submitBtn"])) {
            $idd = $_POST["id"];
            $newname = $_POST["newName"];
            $newsurname = $_POST["newSurname"];
            $newage = $_POST["newAge"];
            $newtown = $_POST["newTown"];
            $neweduca = $_POST["newEducation"];

            $sqlEdit = "UPDATE test_table SET name='$newname', surname='$newsurname', age='$newage', town='$newtown', education='$neweduca' where test_table.ID=$idd";
            mysqli_query($connection, $sqlEdit);
            echo "Edit success";
        }
    ?>
</body>
</html>