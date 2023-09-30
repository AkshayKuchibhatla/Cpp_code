# Results of running howMany.cpp numerous times

C++'s random numbers should generate with uniform distribution according to the book, but we can also see that this holds true in practice. The 5 trials below display the distribution of a quantity of numbers generated randomly over a certain range, using `howMany.cpp`:

### 1. 100 random numbers, 1-10
<table>
    <tr>
        <th>Value</th>
        <th>How many</th>
    </tr>
    <tr>
        <td>0</td>
        <td>8</td>
    </tr>
    <tr>
        <td>1</td>
        <td>8</td>
    </tr>
    <tr>
        <td>2</td>
        <td>6</td>
    </tr>
    <tr>
        <td>3</td>
        <td>11</td>
    </tr>
    <tr>
        <td>4</td>
        <td>18</td>
    </tr>
    <tr>
        <td>5</td>
        <td>8</td>
    </tr>
    <tr>
        <td>6</td>
        <td>9</td>
    </tr>
    <tr>
        <td>7</td>
        <td>10</td>
    </tr>
    <tr>
        <td>8</td>
        <td>15</td>
    </tr>
    <tr>
        <td>9</td>
        <td>7</td>
    </tr>
</table>

Starting off with something simple, we have 100 numbers generated in a range of 1 to 10. If this were perfectly uniformly distributed, each number would appear 10 times. Although it's not that perfect, you can see that each of the numbers appears between 5-20 times, which is near 10. To get more uniform distribution, we need to generate more numbers:

### 2. 10,000 random numbers, 1-10
<table>
    <tr>
        <th>Value</th>
        <th>How many</th>
    </tr>
    <tr>
        <td>0</td>
        <td>991</td>
    </tr>
    <tr>
        <td>1</td>
        <td>1030</td>
    </tr>
    <tr>
        <td>2</td>
        <td>1027</td>
    </tr>
    <tr>
        <td>3</td>
        <td>989</td>
    </tr>
    <tr>
        <td>4</td>
        <td>1011</td>
    </tr>
    <tr>
        <td>5</td>
        <td>965</td>
    </tr>
    <tr>
        <td>6</td>
        <td>963</td>
    </tr>
    <tr>
        <td>7</td>
        <td>974</td>
    </tr>
    <tr>
        <td>8</td>
        <td>1014</td>
    </tr>
    <tr>
        <td>9</td>
        <td>1036</td>
    </tr>
</table>

If this data were perfectly uniform, each number would appear 1000 times. Again, while that's not the case, the numbers are all between 950 and 1050. They are near 1000.

### 3. 100,000 random numbers, 1-10
<table>
    <tr>
        <th>Value</th>
        <th>How many</th>
    </tr>
    <tr>
        <td>0</td>
        <td>10019</td>
    </tr>
    <tr>
        <td>1</td>
        <td>9984</td>
    </tr>
    <tr>
        <td>2</td>
        <td>10151</td>
    </tr>
    <tr>
        <td>3</td>
        <td>9936</td>
    </tr>
    <tr>
        <td>4</td>
        <td>10105</td>
    </tr>
    <tr>
        <td>5</td>
        <td>9943</td>
    </tr>
    <tr>
        <td>6</td>
        <td>10097</td>
    </tr>
    <tr>
        <td>7</td>
        <td>9842</td>
    </tr>
    <tr>
        <td>8</td>
        <td>9894</td>
    </tr>
    <tr>
        <td>9</td>
        <td>10029</td>
    </tr>
</table>

Each number should appear 10000 times if data is normally distributed, and, again, that seems to be close to where the data lies. Each number is randomly generated between 9900 and 10200 times.

### Conclusion
C++'s randomly generated numbers are close to being uniformly distributed, but aren't perfectly there.