"use strict";
class User {
    constructor(id, posts = [], followers = []) {
        this.posts = [];
        this.followers = [];
        this.id = id;
    }
    createPost(content) {
        const postId = this.posts.length + 1;
        const newPost = new Post(postId, this.id, content);
        this.posts.push(newPost);
    }
    comment(post, commentContent) {
        const commentId = post.comments.length + 1;
        const newComment = new Commentt(commentId, this.id, commentContent);
        post.addComment(newComment);
    }
    follow(user) {
        this.followers.push(user);
    }
    likePost(post) {
        post.addLike(this);
    }
    viewFeed() {
        let feed = [];
        for (const followedUser of this.followers) {
            feed = feed.concat(followedUser.posts);
        }
        return feed;
    }
    displayFeed() {
        const feed = this.viewFeed();
        console.log(`Feed của user #${this.id}:`);
        feed.forEach(post => {
            console.log(`[Post #${post.id} từ user #${post.userId}]: ${post.content}`);
        });
    }
}
class Post {
    constructor(id, userId, content, likes = [], comments = []) {
        this.id = id;
        this.userId = userId;
        this.content = content;
        this.likes = likes;
        this.comments = comments;
    }
    addLike(user) {
        this.likes.push(user);
    }
    addComment(comment) {
        this.comments.push(comment);
    }
}
class Commentt {
    constructor(id, userId, content, replies = []) {
        this.id = id;
        this.userId = userId;
        this.content = content;
        this.replies = replies;
    }
    addReply(reply) {
        this.replies.push(reply);
    }
}
const userA = new User(1);
const userB = new User(2);
const userC = new User(3);
userA.createPost("toi la A bai 1");
userA.createPost("toi la A bai 2");
userB.createPost("xin chao moi nguoi");
userB.createPost("hom nay toi an pho");
userC.createPost("hom nay troi dep");
userC.follow(userA);
userC.follow(userB);
userC.likePost(userA.posts[1]);
userC.comment(userA.posts[1], "123adsf");
const postA2 = userA.posts[1];
if (!postA2) {
    console.log("Khong tim thay post thu 2 cua userA");
}
else {
    if (postA2.comments.length === 0) {
        const seed = new Commentt(1, userC.id, "binh luan khoi tao");
        postA2.addComment(seed);
    }
    const cmt = postA2.comments[0];
    const reply = new Commentt(1, userA.id, "Thank");
    cmt.addReply(reply);
}
userC.displayFeed();
