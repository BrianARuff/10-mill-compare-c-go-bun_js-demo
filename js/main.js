function makeAlbums(n) {
  var albums = [];
  for (var i = 0; i < n; i++) {
    albums.push({
      id: i,
      name: "Album " + i,
      artist: "Artist " + i,
      rating: i,
      price: i * 1.5,
    });
  }
  return albums;
}

function mergeSort(albums) {
  if (albums.length < 2) {
    return albums;
  }
  var middle = Math.floor(albums.length / 2);
  var left = mergeSort(albums.slice(0, middle));
  var right = mergeSort(albums.slice(middle));
  return merge(left, right);
}

function merge(left, right) {
  var result = [];
  while (left.length && right.length) {
    if (left[0].rating < right[0].rating) {
      result.push(left.shift());
    } else {
      result.push(right.shift());
    }
  }
  return result.concat(left.slice()).concat(right.slice());
}

function main() {
  console.time("time");

  const n = 10000000;

  var albums = makeAlbums(n);

  var sortedAlbums = mergeSort(albums);

  let count = 0;

  for (let i = 0; i < sortedAlbums.length; i++) {
    if (sortedAlbums[i].rating > count) {
      count = sortedAlbums[i].rating;
    }
  }

  console.log(`\nran ${count} times\n`);

  console.timeEnd("time");

  console.log("\n\n");
}

main();
