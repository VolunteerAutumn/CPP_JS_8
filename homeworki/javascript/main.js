// FETCHING TIME
const search = document.getElementById("search");

search.addEventListener("keydown", (e) => {
  if (e.key === "Enter") {
    fetchUser(search.value);
  }
});

async function fetchUser(username) {
  try {
    const res = await fetch(`https://api.github.com/users/${username}`);
    if (!res.ok) throw new Error("User not found");

    const data = await res.json();

    document.getElementById("avatar").src = data.avatar_url;
    document.getElementById("name").textContent = data.name || "No Name";
    document.getElementById("login").textContent = data.login;

    const github = document.getElementById("github");
    github.textContent = data.html_url;
    github.href = data.html_url;

    const blog = document.getElementById("blog");
    blog.textContent = data.blog || "No Blog";
    blog.href = data.blog || "#";

    document.getElementById("location").textContent = data.location || "Unknown";
    document.getElementById("email").textContent = data.email || "No Email";
    document.getElementById("followers").textContent = data.followers;
    document.getElementById("following").textContent = data.following;

  } catch (err) {
    alert("User not found");
  }
}
